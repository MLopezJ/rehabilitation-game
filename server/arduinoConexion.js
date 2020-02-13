const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
const config = require('./config')

exports.read = async (io) => {

  const COM = config.port;
  const mySerial = new SerialPort(COM,{baudRate:config.serialBegin}, function (err) {
    if (err) {
      return console.log('Error: ', err.message)
      }
  })

  const mySerialParser = mySerial.pipe(new Readline({ delimiter: '\n' }));

  // Read the port data
  mySerial.on("open", () => {
    console.log('* Serial port', COM, ' open');
  });

  await mySerialParser.on('data', data =>{
    console.log(data)
    io.emit('chat message', data);
  });

}