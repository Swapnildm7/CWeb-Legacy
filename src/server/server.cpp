#include "server.hpp"

Server::Server() {
  puts("Initializing...");

  this->pageServer = PageServer(this->app);
  this->staticServer = StaticServer(this->app);
  this->specialServer = SpecialServer(this->app);

  this->pageServer.initPages();
  this->staticServer.initStatics();
  this->specialServer.initSpecials();
}

void Server::run() {
  puts("Running server...");
  this->app.port(PORT_NUMBER)
    .multithreaded()
    .run();
}