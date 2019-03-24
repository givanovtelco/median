#ifndef MEDIAN_HPP__
#define MEDIAN_HPP__

#include <queue>
#include <vector>

template <typename T>
class Median {
public:
    Median(int sz)
        : _nelem(0) {
        std::vector<T> mi;
        std::vector<T> ma;
        mi.reserve(sz);
        ma.reserve(sz);

        _min = std::priority_queue<T, std::vector<T>, std::greater<T>>(
                                                                       std::greater<T>(), std::move(mi));
        _max = std::priority_queue<T, std::vector<T>, std::less<T>>(
                                                                    std::less<T>(), std::move(ma));
    }
    
    void add(const T& t) {
        _max.push(t);
        if (( _nelem % 2 ) == 0 ) {
            if (_min.empty()) {
                _nelem++;
                return;
            }

            if (_max.top() > _min.top()) {
                T maxroot = _max.top();
                _max.pop();
                T minroot = _min.top();
                _min.pop();
                
                _max.push(minroot);
                _min.push(maxroot);
            }
                
        } else {
            _min.push(_max.top());
            _max.pop();
        }
        _nelem++;
    }
  
    double getmedian() {
        if (( _nelem % 2 ) != 0)
            return _max.top();
        return (_max.top() + _min.top()) / 2.0;
    }
  
private:
    int _nelem;
    std::priority_queue<T, std::vector<T>, std::less<T>> _max;
    std::priority_queue<T, std::vector<T>, std::greater<T>> _min;
};

#endif
