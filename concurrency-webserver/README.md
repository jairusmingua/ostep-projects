# Compile the websever
In your linux system, go to the /src folder and do a 'make' command

```sh
make 
```
To clean recompile the files or clean the compiled files
```sh
make clean
```

# How to run the webserver
```sh
./wserver [-d directory of webfiles] [-p port of the websever] 
[-t number of threads] 
```
An example of the websever delivering request to the default src (working directory) at port 5000 with 4 threads
```sh
./wserver -d . -p 5000 -t 4
```


- To open the websever, the default link of the websever is http://localhost:3000