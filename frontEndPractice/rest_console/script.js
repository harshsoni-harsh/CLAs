let consoleForm = document.getElementById("consoleForm");
let requestUrl = document.getElementById("requestUrl");
let responseStatus = document.getElementById("responseStatus");
let requestUrlErrMsg = document.getElementById("requestUrlErrMsg");
let requestMethod = document.getElementById("requestMethod");
let requestBody = document.getElementById("requestBody");
let responseBody = document.getElementById("responseBody");

let req = {
    method: "",
    headers: {
        Authorization: "Bearer 00f3f8fde06120db02b587cc372c3d85510896e899b45774068bb750462acd9f",
        "Content-Type": "application/json",
        Accept: 'application/json'
    },
    body: "",
};
let requestData = {
    body: "",
    url: requestUrl.value,
    method: ""
};

requestUrl.addEventListener("blur", function()
{
    requestData.url = requestUrl.value;
});
requestBody.addEventListener("blur", function()
{
    requestData.body = JSON.stringify(requestBody.textContent);
});
requestMethod.addEventListener('change', function() {
    requestData.method = requestMethod.value;
});
consoleForm.addEventListener('submit', function(event) {
    event.preventDefault();
    if (requestUrl.value === "") {
        requestUrlErrMsg.textContent = "Required*";
    } else {
        requestUrlErrMsg.textContent = "";
    }
    if(requestMethod.value === "PUT")
    {
        req.method = "PUT";
        req.body = requestData.body;
        
        fetch(requestData.url, req)
            .then(function(response) {
                return response.json();
            })
            .then(function(body) {
                responseStatus.value = body.code;
                responseBody.textContent = JSON.stringify(body);
            });
    }
    else if(requestMethod.value === "POST")
    {
        req.method = "POST";
        req.body = requestData.body;
        fetch(requestData.url, req)
            .then(function(response) {
                return response.json();
            })
            .then(function(body) {
                responseStatus.value = body.code;
                responseBody.textContent = JSON.stringify(body);
            });
    }
});