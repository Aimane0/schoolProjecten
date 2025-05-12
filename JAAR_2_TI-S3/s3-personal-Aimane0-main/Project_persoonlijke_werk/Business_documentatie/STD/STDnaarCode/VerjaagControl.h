#include <iostream>

// PLACEHOLDER CLASSES

class Instellingen
{
    bool setAlarmEnabled() {};
    bool getAlarmEnabled() {};
    bool setLightEnabled() {};
    bool getLightEnabled() {};
    bool setServoEnabled() {};
    bool getServoEnabled() {};
    bool setSoundEnabled() {};
    bool getSoundEnabled() {};
};
class DuivenDetector
{
    bool isDuifAanwezig() {};
};
class LichtController
{
    bool maakLichtEffect() {};
};
class ServoController
{
    bool maakWrapperEffect() {};
};
class SoundController
{
    bool maakAfschrikgeluid() {};
};

// EINDE PLACEHOLDERS

class VerjaagControl : public rtos::task<>
{
    enum State
    {
        UIT,
        AAN,
        LICHTEFFECT,
        WAPPEREFFECT,
        GELUIDSEFFECT
    };

public:
    // CONSTRUCTOR (geen idee hoe ik deze zou moeten maken)
    VerjaagControl() {}

    // FLAGS
    rtos::Flag flagAan;
    rtos::Flag flagUit;
    rtos::Flag flagDuifKwam;
    rtos::Flag flagDuifGing;
    rtos::Flag flagLichtKlaar;
    rtos::Flag flagWapperKlaar;
    rtos::Flag flagGeluidKlaar;

    // INTERFACE FUNCTIES
    void zetAan()
    {
        flagAan.set();
    }

    void zetUit()
    {
        flagUit.set();
    }

    void meldDuifAanwezig()
    {
        flagDuifKwam.set();
    }

    void meldDuifVertrokken()
    {
        flagDuifGing.set();
    }

    void meldLichtEffectKlaar()
    {
        flagLichtKlaar.set();
    }

    void meldWapperEffectKlaar()
    {
        flagWapperKlaar.set();
    }

    void meldAfschrikgeluidKlaar()
    {
        flagGeluidKlaar.set();
    }

private:
    State state = UIT;

    Instellingen instellingen;
    DuivenDetector duivenDetector;
    SoundController soundController;
    ServoController servoController;
    LichtController lichtController;

    void main()
    {
        while (true)
        {
            switch (State)
            {
            case UIT:
                wait(flagAan);
                State = AAN;
                break;

            case AAN:
                wait(flagDuifKwam);
                if (instellingen.getLightEnabled())
                {
                    lichtController.maakLichtEffect();
                    State = LICHTEFFECT;
                }
                else if (Instellingen.getServoEnabled())
                {
                    servoController.maakWapperEffect();
                    State = WAPPEREFFECT;
                }
                else if (Instellingen.getSoundEnabled())
                {
                    soundController.maakAfschrikgeluid();
                    State = GELUIDSEFFECT;
                }
                else
                {
                    State = AAN;
                }
                break;

            case LICHTEFFECT:
                wait(flagLichtKlaar);
                if (instellingen.getServoEnabled())
                {
                    servoController.maakWapperEffect();
                    State = WAPPEREFFECT;
                }
                else
                {
                    State = AAN;
                }
                break;

            case WAPPEREFFECT:
                wait(flagWapperKlaar);
                if (instellingen.getSoundEnabled())
                {
                    soundController.maakAfschrikgeluid();
                    State = GELUIDSEFFECT;
                }
                else
                {
                    State = AAN;
                }
                break;

            case GELUIDSEFFECT:
                wait(flagGeluidKlaar);
                State = AAN;
                break;
            }

            // Controleer of de VerjaagControl uitgeschakeld moet worden
            if (flagUit.read())
            {
                State = UIT;
                flagUit.clear();
            }
        }
    }
};