console.dir(document.body);
console.log(document.body);
console.dir(document.head);
console.dir(document.body.childNodes[5]);




// 🔵 🔵  DOM Manipulation


// Selecting with ID:
let ID = document.getElementById("Max");
console.dir(ID);

// Selecting with class:
let classs = document.getElementsByClassName("Max_00");
console.dir(classs)

// Selecting with tag:
let tagss = document.getElementsByTagName("P");
console.dir(tagss);

// Query Selector(Most Useful):

//document.querySelector("ID or Class Or tag");       return first Element;
console.log("First Element");
let element = document.querySelector("p");
console.dir(element);

let element4 = document.querySelector(".Max_00");   // Class name er surute dot(.)likhte hoy.            Ex (.ClassName); 
console.dir(element4);

let element5 = document.querySelector("#Max");  // ID name er surute Has(#)likhte hoy.            Ex (#IdName); 
console.dir(element5);

//document.querySelectorAll("Class Or tag");      return a NodeList;        (Id Diye sudhu single element asbe tai eta use kore lav hobe na)
console.log("All Element");
let element1 = document.querySelectorAll("p");
console.dir(element1);

let element2 = document.querySelectorAll(".Max_00");    // Class name er surute dot(.)likhte hoy.            Ex (.ClassName); 
console.dir(element2);


let element12 = document.querySelector("#min");
console.log(element12);

let id = element12.getAttribute("id");    // to get the attribute value;
console.log(id);

element12.setAttribute("id", "Max001");  // to set the attribute value ("attribute" , "New Value");


// to set the style;
let div = document.querySelector("div");
console.log(div.style);
div.style.backgroundColor = "green";
div.style.fontSize = "20px";



let newBtn = document.createElement("button");    // create new button
newBtn.innerText = "Send!";
console.log(newBtn);

div.append(newBtn);     // adds at the end of node (inside);
div.prepend(newBtn);    // adds at the start of node(inside);
div.before(newBtn);     // adds before the node (outside);
div.after(newBtn);      // adds after the node (Outside);


let pera = document.querySelector("#x00");
console.log(pera);
pera.remove();      // delete node;

let cls = document.querySelector(".a00");
console.log(cls);

cls.classList.add("newClass");      // append new class;

cls.setAttribute("class", "newClass");      // set new class;




// 🔵 🔵 🔵  Chapter-8(Events in JS) 🔵 🔵 🔵



//Inline handling       ( html code boro hoye jay )


//Js  node.event=()=>{ };       (akta node k sudhu akbar handelkora jay)

let btn1 = document.querySelector("#btn1");
console.log(btn1);

btn1.onclick = () => {
    console.log("Button 1 click");
}


let box = document.querySelector("#e00");
console.log(box);

box.onmouseover = () => {
    console.log("Yoy are in the box");
}



// Event Listeners

cls.addEventListener("click", () => {
    console.log("Ok was clicked - handler 1");
});

cls.addEventListener("click", () => {
    console.log("Ok was clicked - handler 2");
});
cls.addEventListener("click", () => {
    console.log("Ok was clicked - handler 3");
});

let handler4 = () => {
    console.log("Ok was clicked - handler 4");
}
cls.addEventListener("click", handler4);



cls.removeEventListener("click", handler4);

let body = document.querySelector("body");
let changeMode = document.querySelector("#mode");

console.log(changeMode);
let current_mode = "light";
changeMode.addEventListener("click", () => {
    if (current_mode === "light") {
        body.classList.remove("light");
        body.classList.add("dark");
        current_mode = "dark";
    }
    else {
        body.classList.remove("dark");
        current_mode = "light";
        body.classList.add("light");
    }
    console.log(current_mode);
});
