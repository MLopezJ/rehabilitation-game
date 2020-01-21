const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');

exports.read = () => {

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

  mySerialParser.on('data', data =>{
  console.log('got word from arduino:', data);
  });

}