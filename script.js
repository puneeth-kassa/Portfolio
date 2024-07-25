// Smooth scrolling to section when clicking on navigation links 
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function(e) {
        e.preventDefault();

        const targetId = this.getAttribute('href').substring(1);
        const targetElement = document.getElementById(targetId);
    
        if (targetElement) {
            window.scrollTo({
                top: targetElement.offsetTop, 
                behavior: 'smooth'
            });
        }
    });
});
    
const topButton = document.getElementById('top-button');
window.addEventListener('scroll', () => {
    if (window.scrollY > 300) {
        topButton.style.display = 'block';
    } else {
        topButton.style.display = 'none';
    }
});
    
// Scroll to top when "Top" button is clicked I
topButton.addEventListener('click', () => {
    window.scrollTo({
        top: 0,
        behavior: 'smooth'
    });
});

const toggleButton = document.createElement('button'); 
toggleButton.textContent = 'Toggle Dark/Light Mode'; 
toggleButton.classList.add('toggle-button'); 
document.body.appendChild(toggleButton);

toggleButton.addEventListener('click', () => { 
    document.body.classList.toggle('dark-mode'); 
});