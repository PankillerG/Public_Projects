#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(
                                  std::function<Result()> func,
                                  int retryCount,
                                  int sleepTime,
                                  bool throwLast) {
    while (retryCount >= 0) {
        try {
            return func();
        } catch (const Exception& error) {
            if (retryCount == 0) {
                if (!throwLast) {
                    std::optional <Result> answer;
                    return answer;
                } else {
                    throw error;
                }
            } else {
                retryCount--;
                Sleep(sleepTime);
            }
        }
    }
}
