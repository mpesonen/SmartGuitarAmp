/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WaveNetVaAudioProcessorEditor::WaveNetVaAudioProcessorEditor (WaveNetVaAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to

    // Set Widget Graphics
    ampSilverKnobLAF.setLookAndFeel(ImageCache::getFromMemory(BinaryData::knob_silver_png, BinaryData::knob_silver_pngSize));

    ampOnButton.setImages(true, true, true,
        ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
        Image(), 1.0, Colours::transparentWhite,
        ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
        0.0);
    addAndMakeVisible(ampOnButton);
    ampOnButton.addListener(this);

    ampCleanLeadButton.setImages(true, true, true,
        ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
        Image(), 1.0, Colours::transparentWhite,
        ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
        0.0);
    addAndMakeVisible(ampCleanLeadButton);
    ampCleanLeadButton.addListener(this);

    ampLED.setImages(true, true, true,
        ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, Colours::transparentWhite,
        Image(), 1.0, Colours::transparentWhite,
        ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, Colours::transparentWhite,
        0.0);
    addAndMakeVisible(ampLED);

    presenceSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, PRESENCE_ID, ampPresenceKnob);
    addAndMakeVisible(ampPresenceKnob);
    ampPresenceKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampPresenceKnob.addListener(this);
    ampPresenceKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampPresenceKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 75, 20);
    ampPresenceKnob.setDoubleClickReturnValue(true, 0.0);

    cleanBassSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, CLEAN_BASS_ID, ampCleanBassKnob);
    addAndMakeVisible(ampCleanBassKnob);
    ampCleanBassKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampCleanBassKnob.addListener(this);
    ampCleanBassKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampCleanBassKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampCleanBassKnob.setDoubleClickReturnValue(true, 0.0);

    cleanMidSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, CLEAN_MID_ID, ampCleanMidKnob);
    addAndMakeVisible(ampCleanMidKnob);
    ampCleanMidKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampCleanMidKnob.addListener(this);
    ampCleanMidKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampCleanMidKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampCleanMidKnob.setDoubleClickReturnValue(true, 0.0);

    cleanTrebleSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, CLEAN_TREBLE_ID, ampCleanTrebleKnob);
    addAndMakeVisible(ampCleanTrebleKnob);
    ampCleanTrebleKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampCleanTrebleKnob.addListener(this);
    ampCleanTrebleKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampCleanTrebleKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampCleanTrebleKnob.setDoubleClickReturnValue(true, 0.0);

    cleanGainSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, CLEAN_GAIN_ID, ampCleanGainKnob);
    addAndMakeVisible(ampCleanGainKnob);
    ampCleanGainKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampCleanGainKnob.addListener(this);
    ampCleanGainKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampCleanGainKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampCleanGainKnob.setDoubleClickReturnValue(true, 0.5);

    leadBassSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LEAD_BASS_ID, ampLeadBassKnob);
    addAndMakeVisible(ampLeadBassKnob);
    ampLeadBassKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampLeadBassKnob.addListener(this);
    ampLeadBassKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampLeadBassKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampLeadBassKnob.setDoubleClickReturnValue(true, 0.0);

    leadMidSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LEAD_MID_ID, ampLeadMidKnob);
    addAndMakeVisible(ampLeadMidKnob);
    ampLeadMidKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampLeadMidKnob.addListener(this);
    ampLeadMidKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampLeadMidKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);;
    ampLeadMidKnob.setDoubleClickReturnValue(true, 0.0);

    leadTrebleSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LEAD_TREBLE_ID, ampLeadTrebleKnob);
    addAndMakeVisible(ampLeadTrebleKnob);
    ampLeadTrebleKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampLeadTrebleKnob.addListener(this);
    ampLeadTrebleKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampLeadTrebleKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampLeadTrebleKnob.setDoubleClickReturnValue(true, 0.0);

    leadGainSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, LEAD_GAIN_ID, ampLeadGainKnob);
    addAndMakeVisible(ampLeadGainKnob);
    ampLeadGainKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampLeadGainKnob.addListener(this);
    ampLeadGainKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampLeadGainKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20);
    ampLeadGainKnob.setDoubleClickReturnValue(true, 0.5);

    masterSliderAttach = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(processor.treeState, MASTER_ID, ampMasterKnob);
    addAndMakeVisible(ampMasterKnob);
    ampMasterKnob.setLookAndFeel(&ampSilverKnobLAF);
    ampMasterKnob.addListener(this);
    ampMasterKnob.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    ampMasterKnob.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 50, 20 );
    ampMasterKnob.setDoubleClickReturnValue(true, 0.5);

    // Size of plugin GUI
    setSize (1085, 540);

    processor.loadConfigAmp();
    resetImages();
}

WaveNetVaAudioProcessorEditor::~WaveNetVaAudioProcessorEditor()
{
    ampPresenceKnob.setLookAndFeel(nullptr);
    ampCleanBassKnob.setLookAndFeel(nullptr);
    ampCleanMidKnob.setLookAndFeel(nullptr);
    ampCleanTrebleKnob.setLookAndFeel(nullptr);
    ampCleanGainKnob.setLookAndFeel(nullptr);
    ampLeadBassKnob.setLookAndFeel(nullptr);
    ampLeadMidKnob.setLookAndFeel(nullptr);
    ampLeadTrebleKnob.setLookAndFeel(nullptr);
    ampLeadGainKnob.setLookAndFeel(nullptr);
    ampMasterKnob.setLookAndFeel(nullptr);
}

//==============================================================================
void WaveNetVaAudioProcessorEditor::paint (Graphics& g)
{

    // Workaround for graphics on Windows builds (clipping code doesn't work correctly on Windows)
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    g.drawImageAt(background_set, 0, 0);  // Debug Line: Redraw entire background image
#else
// Redraw only the clipped part of the background image
    juce::Rectangle<int> ClipRect = g.getClipBounds();
    g.drawImage(background_set, ClipRect.getX(), ClipRect.getY(), ClipRect.getWidth(), ClipRect.getHeight(), ClipRect.getX(), ClipRect.getY(), ClipRect.getWidth(), ClipRect.getHeight());
#endif

}

void WaveNetVaAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    // Amp Widgets
    ampPresenceKnob.setBounds(97, 375, 75, 105);
    ampCleanBassKnob.setBounds(197, 375, 75, 105);
    ampCleanMidKnob.setBounds(280, 375, 75, 105);
    ampCleanTrebleKnob.setBounds(378, 375, 75, 105);
    ampCleanGainKnob.setBounds(456, 375, 75, 105);
    ampLeadBassKnob.setBounds(553, 375, 75, 105);
    ampLeadMidKnob.setBounds(636, 375, 75, 105);
    ampLeadTrebleKnob.setBounds(726, 375, 75, 105);
    ampLeadGainKnob.setBounds(806, 375, 75, 105);
    ampMasterKnob.setBounds(903, 375, 75, 105);

    ampOnButton.setBounds(9, 375, 35, 45);
    ampCleanLeadButton.setBounds(959, 375, 15, 25);

    ampLED.setBounds(975, 40, 15, 25);
}

void WaveNetVaAudioProcessorEditor::buttonClicked(juce::Button* button)
{
    if (button == &ampOnButton) {
        ampOnButtonClicked();
    } else if (button == &ampCleanLeadButton) {
        ampCleanLeadButtonClicked();
    }
}

void WaveNetVaAudioProcessorEditor::ampOnButtonClicked() {
    if (processor.amp_state == 0) {
        processor.amp_state = 1;
    }
    else {
        processor.amp_state = 0;
    }
    resetImages();
}

void WaveNetVaAudioProcessorEditor::ampCleanLeadButtonClicked() {
    if (processor.amp_lead == 1) {
        processor.amp_lead = 0;
        processor.loadConfigAmp();
        processor.set_ampEQ(ampCleanBassKnob.getValue(), ampCleanMidKnob.getValue(), ampCleanTrebleKnob.getValue(), ampPresenceKnob.getValue());
    }
    else  {
        processor.amp_lead = 1;
        processor.loadConfigAmp();
        processor.set_ampEQ(ampLeadBassKnob.getValue(), ampLeadMidKnob.getValue(), ampLeadTrebleKnob.getValue(), ampPresenceKnob.getValue());
    }

    resetImages();
}

void WaveNetVaAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    // Amp

    if (slider == &ampCleanBassKnob || slider == &ampCleanMidKnob || slider == &ampCleanTrebleKnob) {
        if (processor.amp_lead == 0)
            processor.set_ampEQ(ampCleanBassKnob.getValue(), ampCleanMidKnob.getValue(), ampCleanTrebleKnob.getValue(), ampPresenceKnob.getValue());
    }
    else if (slider == &ampLeadBassKnob || slider == &ampLeadMidKnob || slider == &ampLeadTrebleKnob) {
        if (processor.amp_lead == 1)
            processor.set_ampEQ(ampLeadBassKnob.getValue(), ampLeadMidKnob.getValue(), ampLeadTrebleKnob.getValue(), ampPresenceKnob.getValue());       
    }
    else if (slider == &ampPresenceKnob) {
        if (processor.amp_lead == 0)
            processor.set_ampEQ(ampCleanBassKnob.getValue(), ampCleanMidKnob.getValue(), ampCleanTrebleKnob.getValue(), ampPresenceKnob.getValue());
        else if (processor.amp_lead == 1)
            processor.set_ampEQ(ampLeadBassKnob.getValue(), ampLeadMidKnob.getValue(), ampLeadTrebleKnob.getValue(), ampPresenceKnob.getValue());
    }

}

void WaveNetVaAudioProcessorEditor::resetImages()
{
    if (processor.amp_state == 1 && processor.amp_lead == 1 ) {
        background_set = background_lead;
    } else if (processor.amp_state == 1 && processor.amp_lead == 0) {
        background_set = background_clean;
    } else {
        background_set = background_off;
    }
    // Set On/Off amp graphic
    if (processor.amp_state == 0) {
        ampOnButton.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, Colours::transparentWhite,
            0.0);
        ampLED.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::led_blue_off_png, BinaryData::led_blue_off_pngSize), 1.0, Colours::transparentWhite,
            0.0);
    }
    else {
        ampOnButton.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
            0.0);
        ampLED.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::led_blue_on_png, BinaryData::led_blue_on_pngSize), 1.0, Colours::transparentWhite,
            0.0);
    }
    // Set clean/lead switch graphic
    if (processor.amp_lead == 1) {
        ampCleanLeadButton.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::power_switch_down_png, BinaryData::power_switch_down_pngSize), 1.0, Colours::transparentWhite,
            0.0);
    }
    else {
        ampCleanLeadButton.setImages(true, true, true,
            ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
            Image(), 1.0, Colours::transparentWhite,
            ImageCache::getFromMemory(BinaryData::power_switch_up_png, BinaryData::power_switch_up_pngSize), 1.0, Colours::transparentWhite,
            0.0);
    }
    repaint();
}
