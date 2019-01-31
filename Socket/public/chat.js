var socket = io.connect("http://localhost:5000");

// Cookie..
function setCookie(name, value, days) {
  var expires = "";
  if (days) {
    var date = new Date();
    date.setTime(date.getTime() + days * 24 * 60 * 60 * 1000);
    expires = "; expires=" + date.toUTCString();
  }
  document.cookie = name + "=" + (value || "") + expires + "; path=/";
}
function getCookie(name) {
  var nameEQ = name + "=";
  var ca = document.cookie.split(";");
  for (var i = 0; i < ca.length; i++) {
    var c = ca[i];
    while (c.charAt(0) == " ") c = c.substring(1, c.length);
    if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length, c.length);
  }
  return null;
}
function eraseCookie(name) {
  document.cookie = name + "=; Max-Age=-99999999;";
}

//End of Cookie Setup.

// Query DOM
var message = document.getElementById("message");
var handle = getCookie("name");
var btn = document.getElementById("send");
var output = document.getElementById("output");
var feedback = document.getElementById("feedback");

// Emit Events..

function onC() {
  socket.emit("chat", {
    message: message.value,
    handle: handle
  });
  message.value = "";
}

message.addEventListener("keypress", () => {
  socket.emit("typing", `${handle}`);
});

function clearChat() {
  output.innerHTML = "";
  message.value = "";
}

socket.on("chat", data => {
  feedback.innerHTML = "";
  output.innerHTML += `<p><strong>${data.handle} : </strong>  ${
    data.message
  }</p>`;
});

socket.on("typing", data => {
  feedback.innerHTML = `<p><strong>${data} is typing..</strong></p>`;
});
