///////////

function setup () {
  // Write your code here.
  let elements=document.querySelectorAll(".remove");

  for(let element in elements){
    element.addEventListener('click',()=>{
      element.parentNode.remove();
  })
  }
}
setup();






















// function setup () {
//   // Write your code here.
//   let elements=document.querySelectorAll(".remove");
//   for(let i=0;i<elements.length;i++){
//       elements[i].addEventListener('click',()=>{
//         elements[i].parentNode.remove();
      
//     })
//   }
// }
// setup();
