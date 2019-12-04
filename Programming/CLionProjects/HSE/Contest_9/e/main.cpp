#include <memory>
#include "classifiers.h"

class CombinedClassifier {
 private:
    size_t count = 0;
    std::string string_main;
    std::unique_ptr <MainClassifier> main_class = nullptr;
    FastClassifier fast_class;

 public:
    CombinedClassifier(const std::string& for_fast,
                       const std::string& for_slow):
                       fast_class(for_fast), string_main(for_slow)
        {}

    double classify(const std::string& s) {
        double answer;
        try {
            answer = fast_class.classify(s);
        } catch (TooHardObjectException) {
            if (count != 0) {
                answer = (*main_class).classify(s);
            } else {
                count++;
                main_class = std::make_unique <MainClassifier>(string_main);
                answer = (*main_class).classify(s);
            }
        }
        return answer;
    }
};
