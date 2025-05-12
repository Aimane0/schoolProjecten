#include <iostream>
#include <string>

using namespace std;

class DataForUI : public rtos::task<>
{
private:
    enum State
    {
        IDLE,
        WaitingForAction,
        CSVtoUI,
        ShowingToUI
    };

    ui &UI;

    rtos::channel checkLoginChannel;
    rtos::channel exportChannel;
    rtos::channel showChannel;
    rtos::flag flagOptionSelected;

    State state = IDLE;

public:
    status = checkLoginChannel.read();

    void optionSelect()
    {
        flagOptionSelected.set();
    };

    void logOut()
    {
        checkLoginChannel.write(false);
    };

    void exportSelect()
    {
        exportChannel.write(true);
    };

    void showSelect()
    {
        showChannel.write(true);
    };

    void exportDeselect()
    {
        exportChannel.write(false);
    };

    void backButtonpressed()
    {
        showChannel.write(false);
    }

    bool exportCheck = exportChannel.read();
    bool showCheck = showChannel.read();
};

private:
    void main(){
        for(;;){

        }
    }