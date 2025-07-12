let vdom = document.getElementById('virtualDom');
let ndom = document.getElementById('normalDom');

function createElement(){
    ndom.innerHTML = "";
    let nh1 = document.createElement('h1');
    nh1.textContent = "Normal DOM";
    ndom.appendChild(nh1);
}

setInterval(() => {
    createElement();
}, 1000);

let rh1 = React.createElement('h1', null, "Virtual DOM");
ReactDOM.render(rh1, vdom);