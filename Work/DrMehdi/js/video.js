var v = document.querySelector("video");
var t = document.querySelector("track");
var b = document.querySelector("#bar");

v.addEventListener('click',play,false);
v.addEventListener('timeupdate',update,false);
t.addEventListener('loaded',render,false); // Bug in FF31 MAC: wrong event name
t.addEventListener('load',render,false);

function play() {
  if(v.paused) { v.play(); } else { v.pause(); }
}

function update() {
  var p = v.currentTime/v.duration*100;
  b.style.background = "linear-gradient(to right, #F89684 "+p+"%, #9F9F9F "+p+"%)";
}

function render() {
  var c = v.textTracks[0].cues;
  for (var i=0; i<c.length; i++) {
    var s = document.createElement("span");
    s.innerHTML = c[i].text;
    s.setAttribute('data-start',c[i].startTime);
    s.style.width = ((c[i].endTime-c[i].startTime)/62*70-2)+'vw';
    s.addEventListener("click",seek);
    b.appendChild(s);
  }
}

function seek(e) {
  v.currentTime = this.getAttribute('data-start');
  if(v.paused) { v.play(); }
}
