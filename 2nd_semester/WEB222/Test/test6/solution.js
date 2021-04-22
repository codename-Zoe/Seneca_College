//Question 2
window.onload = function(){
    
    //Question 3
    document.title = "Test 6";   // set title to 'Test 6'

    //Question 4
    let tmp = document.querySelector('.intro');  
    let studentId = '123456789'; 
    tmp.innerText = "codename-Zoe";
    tmp.setAttribute('id',studentId);

    //Question 5
    addEventListener('click', function(){
        let start = document.querySelector('button#start');
        start.onclick = function(){
            let elm = document.createElement('div');
            let main = document.querySelector('main');
            elm.innerText = "Start was clicked!";
            main.appendChild(elm);
        }    
    });

    //Question 6
    let num = 1;
    let change = function(){
        let elm = document.querySelector('h1');
        elm.innerText = `There are ${num} div elements in main`;
        num++;
    }
    setInterval(change, 10*1000);
}


