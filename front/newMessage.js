function newMessage(topicName) {
  let eles=document.querySelectorAll('p');
  for(let ele of eles){
    if(ele.getAttribute("data-topic-name")===topicName){
      ele.style.backgroundColor="red";
    }
  }
}
newMessage('discussion');














// function newMessage(topicName) {
//   //Write your code here
//   let elements=document.querySelectorAll("p");
//   for(let i=0;i<elements.length;i++){
//     if(elements[i].getAttribute("data-topic-name")===topicName){
//       elements[i].style.backgroundColor="red";
//     }
//   }
// }

// // Example case
// $('body').html(
//   `<div>
//     <p data-topic-name="discussion">General discussion</p>
//     <p data-topic-name="bugs">Bugs</p>
//     <p data-topic-name="animals">Animals</p>
//   </div>`
// );
newMessage("discussion");
// console.log($('body').html());