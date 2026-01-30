// snake water gun game

// snake - 0   
// water -  1    
// gun -  2     
choices= ["Snake", "Water", "Gun"];

// 0 beats 1 , 1 beats 2 , 2 beats 0
// C   U  
// 1 , 2 -> 1 C
// 0, 1 -> 0 C
// 2, 0 -> 2 C


// 0 , 2 -> 2 U
// 1 , 0 -> 0 U
// 2 , 1 -> 1 U


// if(user == (computer+1)%3 ){
//   console.log("user wins");
// }
//   else if  (user==computer){
//     console.log("draw");
//   }
//   else{
//     //computer wins
//     console.log("computer wins")
//   }

document.getElementById("snakeButton").onclick(
  ()=>{
    computer= Math.floor((Math.random()*3));
    


  }
)