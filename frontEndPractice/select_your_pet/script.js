let petsImageUrls = {
    dog: "https://cdn.pixabay.com/photo/2019/12/18/10/07/friendly-4703564_640.jpg",
    cat: "https://cdn.pixabay.com/photo/2017/02/20/18/03/cat-2083492_640.jpg",
    parrot: "https://cdn.pixabay.com/photo/2018/08/12/16/59/parrot-3601194_1280.jpg",
    spider: "https://cdn.pixabay.com/photo/2013/05/14/16/28/spider-111075_640.jpg",
    rabbit: "https://cdn.pixabay.com/photo/2021/04/17/23/58/bunny-6187026_960_720.jpg"
};

let petSelect = document.getElementById("petSelect");
let petImg = document.getElementById("petImg");
petImg.setAttribute("src", petsImageUrls.dog);
petSelect.addEventListener("change", function(event) {
    petImg.src = petsImageUrls[event.target.value];
});