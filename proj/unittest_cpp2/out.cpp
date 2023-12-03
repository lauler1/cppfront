
#define CPP2_USE_SOURCE_LOCATION Yes
#define CPP2_INCLUDE_STD         Yes

//=== Cpp2 type declarations ====================================================


#include "cpp2util.h"

#line 1 "tests.cpp2"

#line 3 "tests.cpp2"
class Test;
 

#line 47 "tests.cpp2"
class TestSuite;

#line 85 "tests.cpp2"
class TestRunner;
 

//=== Cpp2 type definitions and function declarations ===========================

#line 1 "tests.cpp2"
//#include <unordered_map>

#line 3 "tests.cpp2"
class Test {

    public: Test(Test const& that);
#line 5 "tests.cpp2"
    public: auto operator=(Test const& that) -> Test& ;

#line 10 "tests.cpp2"
    public: Test(Test&& that) noexcept;
#line 10 "tests.cpp2"
    public: auto operator=(Test&& that) noexcept -> Test& ;

#line 17 "tests.cpp2"
 public: explicit Test(std::string&& name, cpp2::in<std::function<void()>> testFunc);

#line 22 "tests.cpp2"
    public: auto run() const& -> void;

#line 27 "tests.cpp2"
    private: std::string name_; 
    private: std::function<void()> testFunc_; 
};

class Test2 {
public:
    Test2(std::string name, std::function<void()> testFunc)
        : name_(std::move(name)), testFunc_(std::move(testFunc)) {}

    void run() const {
        std::cout << "Test Running test: " << name_ << std::endl;
        testFunc_();
    }

private:
    std::string name_;
    std::function<void()> testFunc_;
};

#line 47 "tests.cpp2"
class TestSuite {

    public: TestSuite(TestSuite const& that);
#line 49 "tests.cpp2"
    public: auto operator=(TestSuite const& that) -> TestSuite& ;

#line 54 "tests.cpp2"
    public: TestSuite(TestSuite&& that) noexcept;
#line 54 "tests.cpp2"
    public: auto operator=(TestSuite&& that) noexcept -> TestSuite& ;

#line 60 "tests.cpp2"
    public: explicit TestSuite(cpp2::in<std::string> name, cpp2::in<std::function<void(std::add_lvalue_reference_t<TestSuite>)>> suiteFunc);

#line 65 "tests.cpp2"
    public: explicit TestSuite(cpp2::in<std::function<void(TestSuite)>> suiteFunc);
#line 65 "tests.cpp2"
    public: auto operator=(cpp2::in<std::function<void(TestSuite)>> suiteFunc) -> TestSuite& ;

#line 70 "tests.cpp2"
    public: auto addTest(std::string&& name, std::function<void()>&& testFunc) & -> void;

#line 74 "tests.cpp2"
    public: auto run() const& -> void;

#line 81 "tests.cpp2"
    private: std::string name_ {""}; 
    private: std::vector<Test> tests_ {}; 
};

class TestRunner {
 private: std::vector<TestSuite> suites_; 

    public: auto addSuite(cpp2::in<TestSuite> suite) & -> void;

#line 92 "tests.cpp2"
    public: auto run() const& -> void;
 public: TestRunner() = default;
 public: TestRunner(TestRunner const&) = delete; /* No 'that' constructor, suppress copy */
 public: auto operator=(TestRunner const&) -> void = delete;


#line 97 "tests.cpp2"
};

// Usage example
TestRunner TEST;

void suit1(TestSuite& suite) {
    suite.addTest("Example Test 1.1", [] {
        std::cout << "This is test case 1.1" << std::endl;
    });

    suite.addTest("Example Test 1.2", [] {
        std::cout << "This is test case 1.2" << std::endl;
    });
};

auto suit2(TestSuite& suite) -> void;

#line 123 "tests.cpp2"
[[nodiscard]] auto main() -> int;

//=== Cpp2 function definitions =================================================

#line 1 "tests.cpp2"

#line 5 "tests.cpp2"
    Test::Test(Test const& that)
        : name_{ that.name_ }
        , testFunc_{ that.testFunc_ }{

#line 8 "tests.cpp2"
  std::cout << "Test2 Copy constructor\n";
    }
#line 5 "tests.cpp2"
    auto Test::operator=(Test const& that) -> Test& {
        name_ = that.name_;
        testFunc_ = that.testFunc_;

#line 8 "tests.cpp2"
  std::cout << "Test2 Copy constructor\n";
        return *this;
#line 9 "tests.cpp2"
    }
    Test::Test(Test&& that) noexcept
        : name_{ std::move(that).name_ }
        , testFunc_{ std::move(that).testFunc_ }{

#line 13 "tests.cpp2"
  std::cout << "Test2 Move constructor\n";
    }
#line 10 "tests.cpp2"
    auto Test::operator=(Test&& that) noexcept -> Test& {
        name_ = std::move(that).name_;
        testFunc_ = std::move(that).testFunc_;

#line 13 "tests.cpp2"
  std::cout << "Test2 Move constructor\n";
        return *this;
#line 14 "tests.cpp2"
    }

#line 17 "tests.cpp2"
 Test::Test(std::string&& name, cpp2::in<std::function<void()>> testFunc)
  : name_{ std::move(name) }
  , testFunc_{ testFunc }{

#line 20 "tests.cpp2"
 }

    auto Test::run() const& -> void{
        std::cout << "Test2 Running test: " << name_ << std::endl;
        testFunc_();
    }

#line 49 "tests.cpp2"
    TestSuite::TestSuite(TestSuite const& that)
        : name_{ that.name_ }
        , tests_{ that.tests_ }{

#line 52 "tests.cpp2"
  std::cout << "TestSuite Copy constructor\n";
    }
#line 49 "tests.cpp2"
    auto TestSuite::operator=(TestSuite const& that) -> TestSuite& {
        name_ = that.name_;
        tests_ = that.tests_;

#line 52 "tests.cpp2"
  std::cout << "TestSuite Copy constructor\n";
        return *this;
#line 53 "tests.cpp2"
    }
    TestSuite::TestSuite(TestSuite&& that) noexcept
        : name_{ std::move(that).name_ }
        , tests_{ std::move(that).tests_ }{

#line 57 "tests.cpp2"
  std::cout << "TestSuite Move constructor\n";
    }
#line 54 "tests.cpp2"
    auto TestSuite::operator=(TestSuite&& that) noexcept -> TestSuite& {
        name_ = std::move(that).name_;
        tests_ = std::move(that).tests_;

#line 57 "tests.cpp2"
  std::cout << "TestSuite Move constructor\n";
        return *this;
#line 58 "tests.cpp2"
    }

    TestSuite::TestSuite(cpp2::in<std::string> name, cpp2::in<std::function<void(std::add_lvalue_reference_t<TestSuite>)>> suiteFunc)
  : name_{ name }{

#line 62 "tests.cpp2"
  suiteFunc((*this));
 }

    TestSuite::TestSuite(cpp2::in<std::function<void(TestSuite)>> suiteFunc){
        suiteFunc((*this));

    }
#line 65 "tests.cpp2"
    auto TestSuite::operator=(cpp2::in<std::function<void(TestSuite)>> suiteFunc) -> TestSuite& {
        name_ = "";
        tests_ = {};
#line 66 "tests.cpp2"
        suiteFunc((*this));
        return *this;

#line 68 "tests.cpp2"
    }

    auto TestSuite::addTest(std::string&& name, std::function<void()>&& testFunc) & -> void{
        static_cast<void>(CPP2_UFCS(emplace_back, tests_, std::move(std::move(name)), std::move(std::move(testFunc))));
    }

    auto TestSuite::run() const& -> void{
        std::cout << "TestSuite Running suite: " << name_ << std::endl;
  for ( auto const& test : tests_ ) {
            CPP2_UFCS_0(run, test);
        }
    }

#line 88 "tests.cpp2"
    auto TestRunner::addSuite(cpp2::in<TestSuite> suite) & -> void{
        CPP2_UFCS(push_back, suites_, std::move(suite));
    }

    auto TestRunner::run() const& -> void{
  for ( auto const& suite : suites_ ) {
            CPP2_UFCS_0(run, suite);
        }
    }

#line 112 "tests.cpp2"
auto suit2(TestSuite& suite) -> void{

    CPP2_UFCS(addTest, suite, "Example Test 2.1", []() -> void{
        std::cout << "This is test case 2.1" << std::endl;
    });

    CPP2_UFCS(addTest, suite, "Example Test 2.2", []() -> void{
        std::cout << "This is test case 2.2" << std::endl;
    });
}

[[nodiscard]] auto main() -> int{

 //test2: Test2 = ("asdgf", :()={std::cout << "testFunc_ running" << std::endl;});
 //test2.run();

    CPP2_UFCS(addSuite, TEST, TestSuite("Suite 1", suit1));

    CPP2_UFCS(addSuite, TEST, TestSuite("Suite 2", suit2));

    CPP2_UFCS_0(run, TEST);
    return 0; 
}

