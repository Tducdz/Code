var myInfo = {
    name: 'Trung Duc',
    age: 18,
    address: 'Thanh Hoa, VN',
    getName: function() {
        return this.name
    }
}

delete myInfo.age

console.log(myInfo.getName())