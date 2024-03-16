// input:[ { country: 'India', export: 2000 }, { country: 'USA', export: 100} ]
// output: { 'India': 2000, 'USA': 100 }

const arr = [
    { country: "India", export: 2000 },
    { country: "USA", export: 100 },
    { country: "India", export: 1000 },
  ];
  const ans = arr.reduce((prev, curr) => {
    return {
      ...prev,
      [curr.country]: (prev?.[curr.country] ?? 0) + curr.export,
    };
  }, {});
  
  console.log(ans);
  