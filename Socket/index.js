const express = require("express");
const app = express();
const port = 5000;
const socket = require("socket.io");
const bodyparser = require("body-parser");
const cookieparser = require("cookie-parser");
var users = [];

app.use(bodyparser.urlencoded({ extended: false }));
app.use(bodyparser.json());
app.use(cookieparser());

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/public/index.html");
});

app.post("/goToChat", (req, res) => {
  if (
    users.indexOf(req.body.name) === -1 &&
    req.cookies.name !== req.body.name
  ) {
    res.cookie("name", req.body.name);
    users.push(req.body.name);
    res.sendFile(__dirname + "/public/chat.html");
  } else {
    console.log("Username already taken!!");
  }
});

app.use(express.static("public"));

const server = app.listen(port, () => {
  console.log(`Server at ${port}`);
});

connection = [];

// Socket.io
const io = socket(server);

io.on("connection", socket => {
  console.log("Made Socket Connection!");
  connection.push(socket.id);

  console.log(users);

  socket.on("chat", data => {
    io.sockets.emit("chat", data);
  });

  socket.on("disconnect", function() {
    connection.splice(connection.indexOf(connection), 1);
    var index = users.indexOf(req.body.name);
    if (index > -1) {
      users.splice(index, 1);
      console.log("user disconnected..");
    }
    io.emit("user disconnected");
  });

  socket.on("typing", data => {
    socket.broadcast.emit("typing", data);
  });
});
