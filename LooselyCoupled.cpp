#include <iostream>
#include <random> 
#include <string>
#include <cassert>
using namespace std;

class ICloudCommunicator {
    public:
        virtual int pushMessage(string message) = 0;
};

class IOTCloudCommunicator: public ICloudCommunicator{
    public:
          int  pushMessage(string message){
            
            //Interact with internet and push the message to MessageQueue
            //if communiction succesfull return value from ramge {200 -400} status code otherwise returns errocode (400 - 500)
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(200, 500);
            return distr(gen);
          }
};

class ISpeedSensor{
public:
    virtual int getCurrentSpeed() = 0;
};

class BNFSpeedSensor: public ISpeedSensor{
        public:
            int  getCurrentSpeed(){
                    
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> distr(1, 100);
                    return distr(gen);
            }
};

class IMessageLogger{
    public:
    virtual void write(const string& message)=0;
    virtual ~IMessageLogger(){}
};
class TerminalLogger:public IMessageLogger{
    public:
    void write(const string& message){
        cout<<message<<endl;
    }
};
class SpeedMonitor{
    private : 
        int _speedThreshold;
        ISpeedSensor* _speedSensorInstance;
        ICloudCommunicator* _cloudCommuniccator;
        IMessageLogger* _logger;
  
      public:
      
          SpeedMonitor(ISpeedSensor* sensor, ICloudCommunicator* communicator,IMessageLogger* logger, int speedThreshold): 
          _speedThreshold{speedThreshold}, _speedSensorInstance {sensor}, _cloudCommuniccator{communicator},
          _logger{logger}{}

          void monitor(){

            if(_speedThreshold  < 1 || _speedThreshold > 100){

                this->_logger->write("_speedThreshold value must be in the ramge {1-100}" + to_string(_speedThreshold));
                return;
            }

            int currentSpeedInKmph= _speedSensorInstance->getCurrentSpeed();
            if(currentSpeedInKmph > _speedThreshold){
                
                double mph = currentSpeedInKmph * 0.621371;
                string message="Current Speed in Miles "+ to_string(mph);
                int statusCode= _cloudCommuniccator->pushMessage(message);

                if(statusCode > 400){

                      //Log Message to Console
                       this->_logger->write("Error In Communication Unable to Contact Server " + message);
                  }
            }  
          }
};

void releaseEnv(){
    
    BNFSpeedSensor speedSensor;
    IOTCloudCommunicator cloudCommunicator;
    TerminalLogger logger;
    SpeedMonitor instance(&speedSensor, &cloudCommunicator, &logger,15);
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
    instance.monitor();
}

//test code
class MockCloudCommunicator: public ICloudCommunicator {
public:
    int statusCode;
    string lastMessage;

    int pushMessage(string message) {
        lastMessage = message;
        return statusCode;
    }
};

class MockSpeedSensor: public ISpeedSensor {
public:
    int speed;
    
    int getCurrentSpeed() {
        return speed;
    }
};

class MockLogger: public IMessageLogger {
public:
    string lastLogMessage;

    void write(const string& message) {
        lastLogMessage = message;
    }
};

void testEnv() {
    
    MockSpeedSensor speedSensor;
    MockCloudCommunicator cloudCommunicator;
    MockLogger logger;

    speedSensor.speed = 20;
    cloudCommunicator.statusCode = 200;

    
    SpeedMonitor monitor(&speedSensor, &cloudCommunicator, &logger, 10);

    monitor.monitor();

    cloudCommunicator.statusCode = 500;
    monitor.monitor();
    assert(logger.lastLogMessage == "Error In Communication Unable to Contact Server Current Speed in Miles 12.427420");
}

int main(){
    testEnv();
}



