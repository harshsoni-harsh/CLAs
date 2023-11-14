// JavaScript for subject categorization

// Function to handle slider change event
function handleSliderChange(event) {
    const sliderValue = event.target.value;
    // You can add code here to update the category for the corresponding subject
    // For example, you can use data attributes or IDs to identify subjects
    // and save the slider values in an array or object.
}

// Add event listeners to all sliders on the page
const sliders = document.querySelectorAll('input[type="range"]');
sliders.forEach(slider => {
    slider.addEventListener('input', handleSliderChange);
});
