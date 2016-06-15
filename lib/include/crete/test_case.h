#ifndef CRETE_TEST_CASE_H
#define CRETE_TEST_CASE_H

#include <iostream>
#include <stdint.h>
#include <vector>
#include <iterator>

namespace crete
{
    struct TestCaseElement
    {
        uint32_t name_size;
        std::vector<uint8_t> name;
        uint32_t data_size;
        std::vector<uint8_t> data;

        template <typename Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            (void)version;

            ar & name_size;
            ar & name;
            ar & data_size;
            ar & data;
        }
    };

    typedef std::vector<TestCaseElement> TestCaseElements;

    class TestCase
    {
    public:
        typedef size_t Priority;

    public:
        TestCase();
        void add_element(const TestCaseElement& e) { elems_.push_back(e); }

        const TestCaseElements& get_elements() const { return elems_; }
        void write(std::ostream& os) const;
        Priority get_priority() const { return priority_; }
        void set_priority(const Priority& p) { priority_ = p; }

        friend std::ostream& operator<<(std::ostream& os, const TestCase& tc);

        template <typename Archive>
        void serialize(Archive& ar, const unsigned int version)
        {
            (void)version;

            ar & elems_;
            ar & priority_;
        }

    protected:
    private:
        TestCaseElements elems_;
        Priority priority_; // TODO: meaningless now. In the future, can be used to sort tests.
    };

    std::ostream& operator<<(std::ostream& os, const TestCaseElement& elem);
    std::ostream& operator<<(std::ostream& os, const TestCase& tc);

    void write(std::ostream& os, const std::vector<TestCase>& tcs);
    void write(std::ostream& os, const std::vector<TestCaseElement>& elems);
    void write(std::ostream& os, const TestCaseElement& elem);
    std::vector<TestCase> read_test_cases(std::istream& is);
    TestCaseElement read_test_case_element(std::istream& is);
    TestCase read_test_case(std::istream& is);
}

#endif // CRETE_TEST_CASE_H
