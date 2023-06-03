//�������� ������ ������ �������� ����.
//�������� �������, ������� ��������� ���� � �������� � ������� � ���������� ������� ��� ������(����� � �����������)� ��������� ������ ����������.
//����������� ������������ ������� � ����� �������� � ����, �����, �������, �������� � ��� �� �����������,����� ��� ����� ��� � �������� �����.
//���� ��������� ������� ��� ������ ��������� ��������, �� ������ ���� ������ �������.

#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

void removeOlderEntries(const fs::path& directoryPath, const std::chrono::system_clock::time_point& thresholdTime)
{
    if (!fs::exists(directoryPath))
    {
        std::cerr << "�������� �� ����������: " << directoryPath << std::endl;
        return;
    }

    const fs::file_time_type thresholdFileTime = fs::file_time_type::clock::now() - (std::chrono::system_clock::now() - thresholdTime);

    for (const auto& entry : fs::directory_iterator(directoryPath))
    {
        const auto lastWriteTime = fs::last_write_time(entry.path());
        if (lastWriteTime < thresholdFileTime)
        {
            if (fs::is_directory(entry.path()))
            {
                removeOlderEntries(entry.path(), thresholdTime);
                fs::remove(entry.path());
            }
            else
            {
                fs::remove(entry.path());
            }
        }
    }

    if (fs::last_write_time(directoryPath) < thresholdFileTime)
    {
        fs::remove_all(directoryPath);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    const fs::path directoryPath = "C:\\c++";  // �������� �� ���� � ������ ��������
    const int ageInDays = 0;  // �������� �� ��� �������� ������� � ����

    const auto currentTime = std::chrono::system_clock::now();
    const auto thresholdTime = currentTime - std::chrono::hours(24 * ageInDays);

    removeOlderEntries(directoryPath, thresholdTime);

    std::cout << "������ ������ ������� �������." << std::endl;

    return 0;
}