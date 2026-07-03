const URL = "https://meowfacts.herokuapp.com/";
const factPara = document.querySelector("#FactPara");
const btn = document.querySelector("#btn");
async function getFacts() {
    console.log("Getting data....");
    let response = await fetch(URL);
    console.log(response);//. JSON format
    let data1 = await response.json();
    //console.log(data1.data[0]);
    factPara.innerText = data1.data[0];
    console.log("data found")
}
btn.addEventListener("click", getFacts)
//getFacts();
