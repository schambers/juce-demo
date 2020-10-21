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
    setSize (400, 300);
    
    addAndMakeVisible (gainSlider);
    gainSlider.setRange (0.0, 1);
    gainSlider.setTextValueSuffix (" db");
    gainSlider.setSkewFactorFromMidPoint (0.5);
    gainSlider.setValue (0.0);
    gainSlider.addListener (this);
    
    addAndMakeVisible (gainLabel);
    gainLabel.setText ("Gain", juce::dontSendNotification);
    gainLabel.attachToComponent (&gainSlider, true);
}

JucedemoAudioProcessorEditor::~JucedemoAudioProcessorEditor()
{
}

//==============================================================================
void JucedemoAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::limegreen);
    g.setOpacity (0.50f);
    g.setFont (18.0f);
    g.drawFittedText ("dkodedbeats.com Plug-In!", getLocalBounds(), juce::Justification::centred, 1);

}

void JucedemoAudioProcessorEditor::resized()
{
    auto sliderLeft = 120;
    gainSlider.setBounds (sliderLeft, 20, getWidth() - sliderLeft - 10, 20);
}

void JucedemoAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.gain = gainSlider.getValue();
}
