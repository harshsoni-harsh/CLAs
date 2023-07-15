let updatePasswordForm = document.getElementById("updatePasswordForm");
let newPassword = document.getElementById("newPassword");
let confirmPassword = document.getElementById("confirmPassword");
let newPasswordErrMsg = document.getElementById("newPasswordErrMsg");
let confirmPasswordErrMsg = document.getElementById("confirmPasswordErrMsg");
let updateBtn = document.getElementById("updateBtn");

function validateNewPassword() {
    if (newPassword.value !== "") {
        newPasswordErrMsg.textContent = "";
    } else {
        newPasswordErrMsg.textContent = "Required*";
    }
}

function validateConfirmPassword() {
    if (newPassword.value !== "") {
        if (confirmPassword.value !== newPassword.value) {
            confirmPasswordErrMsg.textContent = "Passwords must be the same";
        } else {
            confirmPasswordErrMsg.textContent = "";
        }
    }
}
newPassword.addEventListener("blur", validateNewPassword);
confirmPassword.addEventListener("blur", validateConfirmPassword);
updatePasswordForm.addEventListener("submit", function(event) {
    event.preventDefault();
    validateNewPassword();
    validateConfirmPassword();
});