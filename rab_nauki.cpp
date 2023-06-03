//”даление файлов старше заданной даты.
//Ќапишите функцию, котора€ принимает путь к каталогу и возраст и рекурсивно удал€ет все записи(файлы и подкаталоги)с возрастом больше указанного.
//ƒопускаетс€ представл€ть возраст в любых единицах Ц дн€х, часах, минутах, секундах Ц или их комбинаци€х,таких как Ђодин час и двадцать минутї.
//≈сли указанный каталог сам старше заданного возраста, он должен быть удален целиком.

#include <iostream>
#include <filesystem>
#include <chrono>

namespace fs = std::filesystem;

void removeOlderEntries(const fs::path& directoryPath, const std::chrono::system_clock::time_point& thresholdTime)
{
    if (!fs::exists(directoryPath))
    {
        std::cerr << " аталога не существует: " << directoryPath << std::endl;
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
    const fs::path directoryPath = "C:\\c++";  // «амените на путь к вашему каталогу
    const int ageInDays = 0;  // «амените на ваш желаемый возраст в дн€х

    const auto currentTime = std::chrono::system_clock::now();
    const auto thresholdTime = currentTime - std::chrono::hours(24 * ageInDays);

    removeOlderEntries(directoryPath, thresholdTime);

    std::cout << "—тарые записи успешно удалены." << std::endl;

    return 0;
}