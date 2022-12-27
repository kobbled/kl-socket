* compile `echo_server.kl`, and push onto the controller
```
cd build
rossum .. -w -o -t
ninja
kpush
```
* On the controlled reset teach pendent, leave the teach pendent in teach mode. `Shift`+`Fwd` on TP. 
* Go to one of the supplied clients, and run the client code.
  - [python](./python-client/readme.md)
  - [rust](./rust-client/readme.md)
  - [go](./go-client/readme.md)
* Type into the terminal, the TP should echo what you just typed.