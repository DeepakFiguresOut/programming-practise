function updateTime() {
    const date_obj = new Date();
    const hour = date_obj.getHours();
    const minute = date_obj.getMinutes();
    const second = date_obj.getSeconds();
    
    document.getElementById("hour").innerHTML = hour;
    document.getElementById("minute").innerHTML = minute;
    document.getElementById("seconds").innerHTML = second;
}

setInterval(updateTime, 1000);
updateTime();