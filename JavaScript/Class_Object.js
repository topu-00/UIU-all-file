class User {
    constructor(name, email) {
        this.name = name;
        this.email = email;
    }
    viewData() {
        console.log(this.name);
        console.log(this.email);
    }
}

let student1 = new User("Max", "max@gmail.com");
student1.viewData();

class Admin extends User {
    editData(name, email) {
        this.name = name;
        this.email = email;
    }
}

let Admin1 = new Admin();
Admin1.editData("Mini", "mini.@gmail.com");
Admin1.viewData(); 

// Class and Object are Same as others language.(like java);