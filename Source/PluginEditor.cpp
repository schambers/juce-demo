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
    g.setOpacity(0.50f);
    g.setFont (18.0f);
    g.drawFittedText ("dkodedbeats.com Plug-In!", getLocalBounds(), juce::Justification::centred, 1);
}

void JucedemoAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
