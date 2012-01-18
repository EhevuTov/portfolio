// Module dependencies
var zmq = require( 'zeromq' )

// ZeroMQ MSU Subscriber
console.log( "Requesting..." )
request = zmq.createSocket( 'req' )
request.on( 'message', function (data) {
  console.log( data.toString() );
})

// synchronous
request.connect( "tcp://192.168.1.174:3000" )
request.send( 'Oh, Hallo Thar' )

// gracefully exit program
process.on( 'SIGINT', function() {
  console.log( "\ngracefully shutting down from SIGINT (Ctrl-C)" )
  request.close()
})

