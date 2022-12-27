# Socket Messaging

FANUC KAREL library and interface for socket messaging between a robot, and a computer. The robot can either be the client or the server.

## Setup

The `R648: User Socket Message` option must be on the controller for this package to function. This can be added to your Roboguide cell by following the [Add Software Options](docs/add_software_options.md) guide.

A Socket Message Server and(/or) client must be started on the teach pendent for this package to function. For starting a Server on the TP follow [this](docs/add_socket_message_server.md) guide.

## Tests

Various tests will be posted. Look at the server and client code to see how to implement in your own projects. Client code will be written in multiple languages for utility.

### Echo Test

This test will echo what the user types in a terminal on an external computer. This is mainly to test that communication is working between the client and the server. Instructions for the test can be found [here](test/echo-test/readme.md)