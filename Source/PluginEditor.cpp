/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JucedemoAudioProcessorEditor::JucedemoAudioProcessorEditor (JucedemoAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (200, 400);
    
    gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    gainSlider.setRange(-48.0, 0.0);
    gainSlider.setValue(-1.0);
    gainSlider.addListener(this);
    addAndMakeVisible(gainSlider);
}

JucedemoAudioProcessorEditor::~JucedemoAudioProcessorEditor()
{
}

//==============================================================================
void JucedemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void JucedemoAudioProcessorEditor::resized()
{
    gainSlider.setBounds(getLocalBounds());
}

void JucedemoAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &gainSlider)
    {
        audioProcessor.rawVolume = juce::Decibels::decibelsToGain((float)gainSlider.getValue());
        
        // Calculates the gain via raising to power of 10 and dividing by 20
        // audioProcessor.rawVolume = pow(10, gainSlider.getValue() / 20);
    }
}
