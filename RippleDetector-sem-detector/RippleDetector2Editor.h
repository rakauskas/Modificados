#ifndef EXAMPLEEDITOR_H_INCLUDED
#define EXAMPLEEDITOR_H_INCLUDED

#include <EditorHeaders.h>


class RippleInterface;
class RippleDetector2;
class ElectrodeButton;


class RippleDetector2Editor : public GenericEditor,
    public ComboBox::Listener
{
public:
    RippleDetector2Editor(GenericProcessor* parentNode, bool useDefaultParameterEditors);

    virtual ~RippleDetector2Editor();

    void buttonEvent(Button* button);

    void comboBoxChanged(ComboBox* c);

    void updateSettings();                                                                                    //Necessário

    void saveCustomParameters(XmlElement* xml);
    void loadCustomParameters(XmlElement* xml);

private:

//    ScopedPointer<ComboBox> detectorSelector;

    ScopedPointer<UtilityButton> plusButton;

    void addDetector();

    OwnedArray<RippleInterface> interfaces;

    int previousChannelCount;

    Array<Colour> backgroundColours;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RippleDetector2Editor);

};

class RippleInterface : public Component,
    public ComboBox::Listener,
    public Button::Listener
{
public:
    RippleInterface(RippleDetector2*, Colour, int);
    ~RippleInterface();

    void paint(Graphics& g);

    void comboBoxChanged(ComboBox*);
    void buttonClicked(Button*);

    void updateChannels(int);

    void setPhase(int);
    void setInputChan(int);
    void setOutputChan(int);
    void setGateChan(int);

    int getPhase();
    int getInputChan();
    int getOutputChan();
    int getGateChan();

private:

    Colour backgroundColour;

    Path sineWave;
    Font font;

    int idNum;

    RippleDetector2* processor;

    OwnedArray<ElectrodeButton> phaseButtons;

    ScopedPointer<ComboBox> inputSelector;
    ScopedPointer<ComboBox> gateSelector;
    ScopedPointer<ComboBox> outputSelector;

};

#endif  // __RippleDETECTOR2EDITOR_H_136829C6__
