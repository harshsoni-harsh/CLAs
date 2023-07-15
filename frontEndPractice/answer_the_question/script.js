let questionsForm = document.getElementById("questionsForm");
let cityHyderabad = document.getElementById("cityHyderabad");
let cityChennai = document.getElementById("cityChennai");
let cityDelhi = document.getElementById("cityDelhi");
let cityMumbai = document.getElementById("cityMumbai");
let submitBtn = document.getElementById("submitBtn");
let resultMsg = document.getElementById("resultMsg");

let val = "";

cityHyderabad.addEventListener("change", function() {
    val = cityHyderabad.value;
});
cityChennai.addEventListener("change", function() {
    val = cityChennai.value;
});
cityDelhi.addEventListener("change", function() {
    val = cityDelhi.value;
});
cityMumbai.addEventListener("change", function() {
    val = cityMumbai.value;
});

questionsForm.addEventListener("submit", function(event) {
    event.preventDefault();
    if (val === "") {
        resultMsg.style.color = "Red";
        resultMsg.textContent = "Please select an answer";
    } else if (val === "cityDelhi") {
        resultMsg.style.color = "Green";
        resultMsg.textContent = "Correct Answer!";
    } else {
        resultMsg.style.color = "Red";
        resultMsg.textContent = "Incorrect Answer!";
    }
})