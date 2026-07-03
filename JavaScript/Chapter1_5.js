/** @format */

// 🔵 🔵 🔵 Name of the Chapter 🔵 🔵 🔵
// 🔵 🔵 Topic Name ;
// 🔵 Data ;




// 🔵 🔵 🔵 Chapter -1 🔵 🔵 🔵




//🔵 🔵 Create HTML file


// 🔵 HTML File ⬇️
/*
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Document</title>
</head>
<body>
    
</body>
<script src="first.js"></script>   // 🔵 Connect JavaScript code with HTML; 
</html>  

*/




// 🔵 🔵 Print in JS ;


console.log("Hello Max");
console.log("Hello Michael");




// 🔵 🔵 Data Type


/*
let,const && var
--------------------

🔵 var : Variable can be re-declared and update . A global scope variable ;

🔵 let : variable cannot be re-declare but can be updated. A block scope variable;

🔵 const : Variabe cannot be re-declare or updated. A block scope Variable;


*** Two type of data type one is Primitive and another one is  Non-primitive ;

(*) primitive(7)                  (*) Non-Primative
-----------------                 --------------------
1) Number                         1) Object
2) String
3) Boolean
4) Undefine 
5) Null 
6) BigInt
7) Symble
*/




// 🔵 🔵 Block of code ;


{
	let a = 10;
	console.log(a);
}




// 🔵 🔵 Object


const student = {
	// Object 1
	age: 20,
	Name: "Max",
};
student.Name = "Topu";
console.log(student.Name);
console.log(student["Name"]);
// console.log(student.Name);    console.log(student["Name"]);  This two line are same.The only difference is in syntax.

const profile = {
	// Object 2
	Name: "Max",
	following: 4,
	followers: 5699484,
	isFollow: false,
};
console.log(profile);




// 🔵 🔵 🔵  Chapter-2 🔵 🔵 🔵




// 🔵 🔵  Make Comments
// Same as other language ;




// 🔵 🔵 Operators
// Same as other language


/*
🔵New ⬇️
--------
a^n = a ** n;
b^n = b ** n;
5^3 =5 ** 3 = 125 ;

*/




// 🔵 🔵 Assignment Operators
// Same as other language




// 🔵 🔵 Comparison Operators
// Mostly same as other language


// 🔵 New ⬇️
let x = 5;
let y = "5";

if (x == y) {
	// Condition true becouse,if a string contain only number then the string first convert into a Number and then the condition check;;
	console.log("True");
}

if (x === y) {
	// If we want to compare data and data type then we can use this ; It's called Strict version for check Equal to & Data type;
}

let a = 5;
let b = "5";
console.log(a !== b);




// 🔵 🔵 Conditional Statements
// Same as other language




// 🔵 🔵  MDN Docs


/*
If you want to reecharge something about HTML/CSS/JavaScript you can click this link  https://developer.mozilla.org/en-US/ or You can Search "MDN web Docs" and then search on the docs which topic you want learn;
*/




// 🔵 🔵 User Input


let Name = prompt("Enter Input:");
console.log(Name);




// 🔵 🔵 🔵  Chapter-3 🔵 🔵 🔵




// 🔵 🔵 Loops
// Same as othe language;


// for-of loop
// ------------

let str = "HeloWorld";
for (let val of str) {
	console.log(val);
}

// for-in loop
// ------------
for (let key in profile) {
	console.log(key);
	console.log(profile[key]);
}




// 🔵 🔵 String
// Same as other language




// 🔵 🔵 Template Literals(Special type of string)
// --------------------------------------------------


let santence = `This is a template literals`;
console.log(santence);
let obj = {
	item: "pen",
	price: 10,
};
console.log("The cost of ", obj.item, "is ", obj.price, "Taka");
console.log(`the cost of ${obj.item} is ${obj.price} taka`); // using template literals;
// console.log("The cost of ",obj.item,"is ",obj.price,"Taka");     console.log(`the cost of ${obj.item} is ${obj.price} taka`);     This two line are same.The only difference is in syntax.




// 🔵 🔵 String Methods


let str2 = "Michael Max";
str2 = str2.toUpperCase();
console.log(str2);

str2 = str2.toLocaleLowerCase();
console.log(str2);

let str3 = "    Michael     Max     ";
console.log(str3.trim());

let str4 = "Michael ";
console.log(str4.slice(1, 4)); //Return part of String;

let str5 = "Michael";
console.log(str4.concat(str));
console.log(str4 + str);
//console.log(str4.concat(str));      console.log(str4 + str);        This two line are  same.

console.log(str4.replace("h", "X"));

console.log(str4.charAt(4));




// 🔵 🔵 🔵  Chapter-4 🔵 🔵 🔵




// 🔵 🔵 Array
// Same as other language ;

let arr = [1, 2, 3, 4, 5, 6, 7];

// add element
arr.splice(2, 0, 55);
console.log(arr);

// Delete element
arr.splice(3, 1);
console.log(arr);

//replace element
arr.splice(3, 1, 101);
console.log(arr);




// 🔵 🔵 🔵  Chapter-5 🔵 🔵 🔵




// 🔵 🔵 Functions
// Same as other language ;

function printFunction() {
	console.log("Hello Max");
	console.log("Hello Michael");
}

printFunction();
printFunction();

function newFunction(msg) {
	console.log(msg);
}
newFunction("Good Morning");


// 🔵 🔵 Arrow Functions


const printFunc = () => {
	console.log("Hello World!");
};
printFunc();

const arrowSum = (a, b) => {
	console.log("a+b =", a + b)
};
arrowSum(10, 2);


// Practice Problem: Vowels Count;


function countVowels(Val) {
	let count = 0;
	for (let v of Val) {
		if (v === "a" || v === "e" || v === "i" || v === "o" || v === "u" || v === "A" || v === "E" || v === "I" || v === "O" || v === "U") {
			count++;
		}
	}
	return count;
}

let strX = prompt("Enter Input");
let Count = countVowels(strX);
console.log("Total Vowels: ", Count);


// Practice Problem: Vowels Count(Using Arrow Function);


const countVow = (val) => {
	let count = 0;
	for (let v of Val) {
		if (v === "a" || v === "e" || v === "i" || v === "o" || v === "u" || v === "A" || v === "E" || v === "I" || v === "O" || v === "U") {
			count++;
		}
	}
	return count;
}
let strA = prompt("Enter Input");
let CountA = countVowels(strX);
console.log("Total Vowels: ", Count);


function abc() {
	console.log("Hello Abc");
}
function def(kkk) {
	return kkk();
}
def(abc);


// 🔵 🔵 forEach Loop in Array (Only Use for  Array not for String) Higher Order Function Becouse it can take or return other function;
// (Problem ache dekha lagbe aro valo kore array mathood o problem ache);

let ar = [1, 2, 3, 4, 5, 6];

ar.forEach(function (val) {
	console.log(val);
});

// Using arrowFunction;

ar.forEach((val) => {
	console.log(val);
});


// Practice Problem: Square of a number (Using Arrow Function);

let num = [2, 3, 4];
let calcSquare = (num) => {
	console.log(num ** 2);
}
num.forEach(calcSquare);
