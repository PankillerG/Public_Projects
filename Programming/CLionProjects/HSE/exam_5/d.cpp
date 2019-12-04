#include <string>

class NotifierBase {
 public:
    virtual void Notify(const std::string& message) const {}
};

class EmailNotifier: public NotifierBase {
 private:
    std::string sms_mail;

 public:
    EmailNotifier(const std::string& str): sms_mail(str) {}

    void Notify(const std::string& message) const {
        SendEmail(sms_mail, message);
    }
};

class SmsNotifier: public NotifierBase {
 private:
    std::string sms;

 public:
    SmsNotifier(const std::string& str): sms(str) {}

    void Notify(const std::string& message) const {
        SendSms(sms, message);
    }
};
