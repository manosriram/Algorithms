const express = require("express");
const app = express();
const port = 5000;
const socket = require("socket.io");
const bodyparser = require("body-parser");
const cookieparser = require("cookie-parser");
var name;
var users = [];
connection = [];
app.use(bodyparser.urlencoded({ extended: false }));
app.use(bodyparser.json());
app.use(cookieparser());

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/public/index.html");
});

app.post("/goToChat", (req, res) => {
    name = req.body.name;
    users.push(name);
    res.cookie("name", req.body.name);
     
    res.sendFile(__dirname + "/public/chat.html");
});

app.use(express.static("public"));

const server = app.listen(port, () => {
  console.log(`Server at ${port}`);
});



// Socket.io
const io = socket(server);

io.on("connection", socket => {
  console.log("Made Socket Connection!");
    connection.push(socket.id);
    console.log(users);
    console.log(connection);
    var latestUser = users[users.length-1];
  socket.on("chat", data => {
    io.sockets.emit("chat", data);
  });

    socket.on("disconnect", function() {
	var index = connection.indexOf(socket.id);
	connection.splice(index,1);
	users.splice(index,1);
      io.emit("user disconnected");
      console.log(users);
  });

  socket.on("typing", data => {
    socket.broadcast.emit("typing", data);
  });
});
 
