#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SPowerData
{
public:
    float m_Amp;
    float m_Res;
    float m_Power;
};

class CPowerInfo
{
private:
    SPowerData *m_power_array;
    int m_numElements;
    fstream m_File;

public:
    CPowerInfo()
    {
        m_power_array = nullptr;
        m_numElements = 0;
    }

    ~CPowerInfo()
    {
        if (m_power_array != nullptr)
        {
            delete[] m_power_array;
            m_power_array = nullptr;
        }
    }

    int getNumElements(string pFile)
    {
        m_File.open(pFile, ios::in);
        if (!m_File.is_open())
        {
            return 0;
        }
        float amp, res;
        int count = 0;
        while (m_File >> amp >> res)
        {
            count++;
        }
        m_File.close();
        m_numElements = count;
        return m_numElements;
    }

    void LoadData(string pFile, int numElements)
    {
        m_numElements = numElements;
        if (m_numElements <= 0) return;

        m_power_array = new SPowerData[m_numElements];
        m_File.open(pFile, ios::in);
        if (!m_File.is_open())
        {
            return;
        }

        cout << "\n Total elements :" << m_numElements;

        for (int i = 0; i < m_numElements; i++)
        {
            m_File >> m_power_array[i].m_Amp >> m_power_array[i].m_Res;
            m_power_array[i].m_Power = m_power_array[i].m_Amp * m_power_array[i].m_Amp * m_power_array[i].m_Res;
            cout << "\n" << m_power_array[i].m_Amp << "\t" << m_power_array[i].m_Res;
        }
        m_File.close();
        cout << endl;
    }

    void FindMinMaxPower(float &outMinPower, float &outMaxPower)
    {
        if (m_numElements <= 0 || m_power_array == nullptr) return;

        outMinPower = m_power_array[0].m_Power;
        outMaxPower = m_power_array[0].m_Power;

        for (int i = 1; i < m_numElements; i++)
        {
            if (m_power_array[i].m_Power < outMinPower)
            {
                outMinPower = m_power_array[i].m_Power;
            }
            if (m_power_array[i].m_Power > outMaxPower)
            {
                outMaxPower = m_power_array[i].m_Power;
            }
        }
    }
};

int main()
{
    CPowerInfo pw;
    int numElements = pw.getNumElements("AmpRes.txt");

    pw.LoadData("AmpRes.txt", numElements);

    float minpower, maxpower;
    pw.FindMinMaxPower(minpower, maxpower);

    cout << "\n The minimum power = " << minpower;
    cout << "\n The maximum power = " << maxpower;
    cout << endl;

    return 1;
}