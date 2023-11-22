#ifndef FORMA_HPP
#define FORMA_HPP

class Forma {
   public:
    virtual ~Forma() = default;
    virtual const double area() const = 0;
};

#endif
