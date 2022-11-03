# Vōcal☆Shōjo (ᗜˬᗜ)

Fast and light script to extract a specific frequency like vocal from an audio clip 

## Dataset Acquisition

An arbitrary audio clip in WAV format

## Data Format

WAV *(io via using [AudioFile library](https://github.com/adamstark/AudioFile))*

## Data Correction

Check if the input file is in valid WAV audio format

## Data Storage

2D vector to storage raw audio data, and using KDTree 

## Algorithm 

We use KDTree to process our data, and find the nearest target frequency in the tree so that we can remove them.

## Timeline

11/06: create the frame of the project, and write 50% unit test

11/07-11/19: implement the audio2vector(), KDTree class 

Fall break: finish KDTree getNeighbor() and RemoveFreq() method

-Deadline: pass the unit test and FINISHED!
