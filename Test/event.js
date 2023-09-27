const sourceMediumPlatform = (referrer = "", utmURL = "") => {
  let details = { source: "", medium: "", platform: "" };

  const sources = [
    "instagram",
    "email",
    "facebook",
    "twitter",
    "google",
    "bing",
  ];
  const platforms = [
    "instagram",
    "facebook",
    "twitter",
    "klaviyo",
    "google",
    "bing",
  ];
  const mediums = ["cpc", "referrel", "affiliate", "social", "email"];

  if (utmURL !== "") {
    let queryString = utmURL.split("?")[1];
    var obj = {};
    if (queryString) {
      queryString = queryString.split("#")[0];
      var arr = queryString.split("&");
      for (var i = 0; i < arr.length; i++) {
        var a = arr[i].split("=");
        var paramName = a[0];
        var paramValue = typeof a[1] === "undefined" ? true : a[1];
        paramName = paramName.toLowerCase();
        if (typeof paramValue === "string")
          paramValue = paramValue.toLowerCase();
        if (paramName.match(/\[(\d+)?\]$/)) {
          var key = paramName.replace(/\[(\d+)?\]/, "");
          if (!obj[key]) obj[key] = [];
          if (paramName.match(/\[\d+\]$/)) {
            var index = /\[(\d+)\]/.exec(paramName)[1];
            obj[key][index] = paramValue;
          } else {
            obj[key].push(paramValue);
          }
        } else {
          if (!obj[paramName]) {
            obj[paramName] = paramValue;
          } else if (obj[paramName] && typeof obj[paramName] === "string") {
            obj[paramName] = [obj[paramName]];
            obj[paramName].push(paramValue);
          } else {
            obj[paramName].push(paramValue);
          }
        }
      }

      details.source = obj?.["utm_source"];

      details.medium = obj?.["utm_medium"];
    }
  }
  if (details.source === "") {
    sources.forEach((source, index) => {
      if (
        referrer.toLowerCase().includes(source.toLowerCase()) ||
        utmURL.toLowerCase().includes(source.toLowerCase())
      ) {
        details.source = source;
      }
    });
  }

  // mediums.forEach((medium, index) => {
  //   if (
  //     referrer.toLowerCase().includes(medium.toLowerCase()) ||
  //     utmURL.toLowerCase().includes(medium.toLowerCase())
  //   ) {
  //     details.medium = medium;
  //   }
  // });
  platforms.forEach((platform, index) => {
    if (
      referrer.toLowerCase().includes(platform.toLowerCase()) ||
      utmURL.toLowerCase().includes(platform.toLowerCase())
    ) {
      details.platform = platform;
    }
  });

  return { ...details };
};

const getJSessionId = () => {
  if (
    localStorage.getItem("session_start") == null ||
    localStorage.getItem("session_id") == null
  ) {
    localStorage.setItem("session_start", Date.now());
    localStorage.setItem("session_id", Date.now());
  } else if (
    Date.now() - localStorage.getItem("session_start") >
    30 * 60 * 1000
  ) {
    localStorage.removeItem("session_start");
    localStorage.removeItem("session_id");
    localStorage.setItem("session_start", Date.now());
    localStorage.setItem("session_id", Date.now());
  } else {
    localStorage.setItem("session_start", Date.now());
  }
  return localStorage.getItem("session_id");
};

const getUserPseudoId = (userEmail = "") => {
  const userMap = new Map([
    ["fastfrwd+skinny_mixes@bain.com", 1],
    ["fastfrwd+ritual@bain.com", 2],
  ]);

  if (userEmail !== "" && userMap.has(userEmail)) {
    const userId = userMap.get(userEmail);
    if (localStorage.getItem("pseudo_user_id") == null) {
      localStorage.setItem("pseudo_user_id", userId);
    } else {
      localStorage.removeItem("pseudo_user_id");
      localStorage.setItem("pseudo_user_id", userId);
    }
  } else if (userEmail !== "") {
    let userId = userMap.size + 1;
    userMap.set(userEmail, userId);
    if (localStorage.getItem("pseudo_user_id") == null) {
      localStorage.setItem("pseudo_user_id", userId);
    } else {
      localStorage.removeItem("pseudo_user_id");
      localStorage.setItem("pseudo_user_id", userId);
    }
  }
  let userPseudoId =
    localStorage.getItem("pseudo_user_id") == null
      ? "unknown"
      : localStorage.getItem("pseudo_user_id");
  return userPseudoId;
};
var getCustomerId = function () {
  try {
    let curr = window.ShopifyAnalytics.meta.page.customerId;
    if (curr !== undefined && curr !== null && curr !== "") {
      return curr;
    }
  } catch (e) {}
  try {
    let curr = window.meta.page.customerId;
    if (curr !== undefined && curr !== null && curr !== "") {
      return curr;
    }
  } catch (e) {}
  try {
    let curr = _st.cid;
    if (curr !== undefined && curr !== null && curr !== "") {
      return curr;
    }
  } catch (e) {}
  try {
    let curr = ShopifyAnalytics.lib.user().traits().uniqToken;
    if (curr !== undefined && curr !== null && curr !== "") {
      return curr;
    }
  } catch (e) {}
  return null;
};
const getEvent = (
  clientId,
  eventType = "clicked",
  isPurchase = false,
  purchaseRevenue = 0,
  userEmail = "",
  utmURL = document.URL
) => {
  const objectDate = new Date();
  let day = objectDate.getDate();

  let month = objectDate.getMonth();

  let year = objectDate.getFullYear();
  if (day < 10) {
    day = "0" + day;
  }

  if (month < 10) {
    month = `0${month}`;
  }
  let eventDate = `${year}${month}${day}`;
  let eventTimestamp = Date.now();
  const sessionId = getJSessionId();
  // const userPseudoId = getUserPseudoId(userEmail);
  const userPseudoId = getCustomerId();
  const referrer = document.referrer;
  // const utmURL = document.URL;
  const { source, medium, platform } = sourceMediumPlatform(referrer, utmURL);

  if (eventType === "traffic" || eventType === "click") {
    fetch("http://127.0.0.1:5000/api/pixel", {
      method: "POST",
      headers: {
        "X-API-KEY": "surjeet",
        Accept: "application/json",
        "Content-Type": "application/json",
      },
      body: JSON.stringify({
        clientId: clientId,
        eventType: eventType,
        eventDate: eventDate,
        eventTimestamp: eventTimestamp,
        sessionId: sessionId,
        userPseudoId: userPseudoId,
        source: source,
        medium: medium,
        platform: platform,
        isPurchase: isPurchase,
        purchaseRevenue: purchaseRevenue,
        referrer: referrer,
        URL: utmURL,
      }),
    })
      .then((response) => response.text())
      .then((response) => console.log(response))
      .catch((error) => console.error(error));
  }
  console.log(
    "clientId",
    clientId,
    "js Event: ",
    eventType,
    // " and ",
    // !isPurchase ? "traffiC event" : "Purchase Event",
    "eventDate:",
    eventDate,
    "eventTime:",
    eventTimestamp,
    "sessionId:",
    sessionId,
    "userPseudoId:",
    userPseudoId,
    "isPurchase:",
    isPurchase,
    "purchaseRevenue:",
    purchaseRevenue,
    "referrer: ",
    referrer,
    "URL:",
    utmURL,
    "source:",
    source,
    "medium:",
    medium,
    "platform:",
    platform
  );

  return {
    eventType: !isPurchase ? "traffiC event" : "Purchase Event",
    referrer: referrer,
    URL: utmURL,
    eventDate: eventDate,
    eventTimestamp: eventTimestamp,
    sessionId: sessionId,
    userPseudoId: userPseudoId,
    isPurchase: isPurchase,
    purchaseRevenue: purchaseRevenue,
    source: source,
    medium: medium,
    platform: platform,
  };
};

// Function to compare the previous path to the new path
setTimeout(() => {
  getEvent("Surjeet", "traffic");
  let path = document.URL;

  document.body.addEventListener("click", (e) => {
    // console.log("e", e, "p", document.URL, path);
    path = document.URL;
    getEvent("Surjeet", "click");
  });
  document.body.addEventListener("mousemove", () => {
    getEvent("Surjeet", "mouse move");
  });
  // document.getElementById("MainContent").addEventListener("scroll", () => {
  //   getEvent("Surjeet", "scroll");
  // });
  let scrollElement = document.getElementsByClassName("scrollEvent");
  for (let i = 0; i < scrollElement.length; i++) {
    scrollElement[i].addEventListener("scroll", () => {
      getEvent("Surjeet", "scroll");
    });
  }
}, 50);
