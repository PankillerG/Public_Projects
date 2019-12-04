#include <iostream>
#include <stdexcept>
#include <utility>

struct BadOptionalAccess {};

template <typename T>
class Optional {
 private:
    bool defined = false;
    alignas (T) unsigned char data[sizeof(T)];

 public:
    Optional() = default;
    Optional(const T & elem) {
        defined = true;
        new(data) T(elem);
    }
    Optional(T && elem) {
        defined = true;
        new(data) T(std:: move(elem));
    }
    Optional(const Optional & other) {
        try {
            Optional(other.value());
        } catch (...) {
            Optional();
            throw;
        }
    }

    Optional & operator = (const Optional & other) {
        if (!defined) {
            if (other.defined) {
                new(data) T(*other);
                defined = true;
            }
        } else {
            if (!(other.defined)) {
                defined = false;
                reinterpret_cast <T *> (data) -> ~T();
            } else {
                (*this).value() = other.value();
            }
        }
        return *this;
    }
    Optional & operator = (const T & elem) {
        if (!defined) {
            defined = true;
            new(data) T(elem);
        } else {
            (*this).value() = elem;
        }
        return *this;
    }
    Optional & operator = (T && elem) {
        if (!defined) {
            defined = true;
            new(data) T(std:: move(elem));
        } else {
            (*this).value() = std:: move(elem);
        }
        return *this;
    }

    bool has_value() const {
        return defined;
    }

    T & operator * () {
        return (*this).value();
    }
    const T & operator * () const {
        return (*this).value();
    }

    T * operator -> () {
        return reinterpret_cast <T *> (data);
    }
    const T * operator -> () const {
        return reinterpret_cast <const T *> (data);
    }

    T & value() {
        try {
            if (defined) {
                return *reinterpret_cast <T *> (data);
            } else {
                throw BadOptionalAccess();
            }
        } catch (...) {
            throw;
        }
    }

    const T & value() const {
        try {
            if (defined) {
                return *reinterpret_cast <const T *> (data);
            } else {
                throw BadOptionalAccess();
            }
        } catch (...) {
            throw;
        }
    }

    void reset() {
        if (defined) {
            defined = false;
            reinterpret_cast <T *> (data) -> ~T();
        }
    }

    ~Optional() {
        if (defined) {
            reinterpret_cast <T *> (data) -> ~T();
        }
    }
};
