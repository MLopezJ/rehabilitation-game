const http = require('http');
const app = require('./app');
const port = 5000;
const server = http.createServer(app);
const io = require('socket.io')(server);
const arduino = require('./arduinoConexion');

io.on('connection', function(socket){
	arduino.read(io)
});

server.listen(port, () => {
	console.log('* Server is running on port ', port);
});

