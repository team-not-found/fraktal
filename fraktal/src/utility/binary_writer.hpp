#pragma once

#include<fstream>
#include<string>

using namespace std;

// This class enables you to write large amounts of data to a file in binary format.
// Always delete the object to close the [fstream]!
template <class T> class BinaryWriter {
private:
    fstream* output;
public:
    BinaryWriter<T>(string filename) {
        output = new fstream(filename, ios::out | ios::binary);
    }

    ~BinaryWriter() {
        output->close();
        delete(output);
    }

    void write(T value) {
        output->write((char*) &value, sizeof(T));
    }
};