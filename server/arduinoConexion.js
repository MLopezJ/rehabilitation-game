const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

exports.read = async (io) => {

  const COM = 'COM6';
  const mySerial = new SerialPort(COM,{baudRate:9600}, function (err) {
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