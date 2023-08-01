let timer = document.getElementById("timer");
let quoteDisplay = document.getElementById("quoteDisplay");
let result = document.getElementById("result");
let quoteInput = document.getElementById("quoteInput");
let submitBtn = document.getElementById("submitBtn");
let resetBtn = document.getElementById("resetBtn");
let spinner = document.getElementById("spinner");
let count;
let isClicked = 0;
let input = 0;
let time;
submitBtn.addEventListener("click", function() {
    isClicked = 1;
});
quoteInput.addEventListener("keydown", function() {
    input = quoteInput.value;
});
let h1 = document.createElement("h4");
result.appendChild(h1);
let outertime;
let counting;
let wpm;
let len;
let temp;
function getCount(str) {
    return str.split(' ').filter(function(num) {
     return num != ''
    }).length;
   };
let req = function() {
    spinner.classList.remove("d-none");
    fetch("https://apis.ccbp.in/random-quote")
        .then(function(response) {
            spinner.classList.add("d-none");
            quoteInput.value = "";
            count = 0;
            return response.json();
        })
        .then(function(jsonData) {
            quoteDisplay.textContent = jsonData.content;
            clearInterval(time);
            clearInterval(outertime);
            count = 0;
            counting = 0;
            time = setInterval(function() {
                timer.textContent = count + " seconds";
                count++;
                if (isClicked) {
                    if (input == jsonData.content) {
                        clearInterval(time);
                        clearInterval(outertime);
                        h1.textContent = "Well done! Your typing speed is "+wpm.toPrecision(4)+" wpm";
                    } else {
                        h1.textContent = "You typed incorrect sentence.";
                    }
                    isClicked = 0;
                }
            }, 1000);
            outertime = setInterval(function()
            {
                counting++;
                if (input === jsonData.content) {
                    clearInterval(time);
                    clearInterval(outertime);
                    len = getCount(input);
                    wpm = 60 * 20 * len / counting;
                    h1.textContent = "Well done! Your typing speed is "+wpm.toPrecision(4)+" wpm";
                }
            }, 50);
        });
};
resetBtn.addEventListener("click", function() {
    req();
});
req();