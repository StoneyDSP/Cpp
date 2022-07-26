/**
  ==============================================================================

    Atomic.h
    Created: 26 Jul 2022 14:31:09pm
    Author:  Nathan J. Hood
    Website: github.com/StoneyDSP
    email:   nathanjhood@googlemail.com

  ==============================================================================
*/

#pragma once

#ifndef ATOMIC
#define ATOMIC

/** Supplies symbolic names for synchronization operations on memory locations. These operations affect how assignments in one thread become visible in another. */
typedef enum memory_order 
{
    memory_order_relaxed, // No ordering required.
    memory_order_consume, // A load operation acts as a consume operation on the memory location.
    memory_order_acquire, // A load operation acts as an acquire operation on the memory location.
    memory_order_release, // A store operation acts as a release operation on the memory location.
    memory_order_acq_rel, // Combines memory_order_acquire and memory_order_release.
    memory_order_seq_cst, // Combines memory_order_acquire and memory_order_release. Memory accesses that are marked as memory_order_seq_cst must be sequentially consistent.
} memory_order;

template <class Ty>
struct Atomic
{
    Atomic();
    Atomic( const Atomic& );
    Atomic( Ty Value ) noexcept;

    /** Reads and returns the stored value. */
    operator Ty() const volatile noexcept { *this->load(); }
    /** Reads and returns the stored value. */
    operator Ty() const noexcept { *this->load(); }

    /** Uses a specified value to replace the stored value. */
    Ty Atomic<Ty>::operator=(Ty Value) volatile noexcept { store(Value); }
    /** Uses a specified value to replace the stored value. */
    Ty Atomic<Ty>::operator=(Ty Value) noexcept { store(Value); }

    /** Increments the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator++(int) volatile noexcept;
    /** Increments the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator++(int) noexcept;
    /** Increments the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator++() volatile noexcept;
    /** Increments the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator++() noexcept;

    /** Decrements the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator--(int) volatile noexcept;
    /** Decrements the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator--(int) noexcept;
    /** Decrements the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator--() volatile noexcept;
    /** Decrements the stored value. Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator--() noexcept;

    /** Adds a specified value to the stored value. 
     * Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator+=(Ty Value) volatile noexcept;
    /** Adds a specified value to the stored value. 
        Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator+=(Ty Value) noexcept;

    /** Subtracts a specified value from the stored value. 
     * Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator-=(Ty Value) volatile noexcept;
    /** Subtracts a specified value from the stored value. 
        Used only by integral and pointer specializations. */
    Ty Atomic<Ty>::operator-=(Ty Value) noexcept;

    /** Performs a bitwise "and" (&) on a specified value and the stored value of *this. 
        Used only by integral specializations. */
    Atomic<Ty>::operator&= (Ty Value) volatile noexcept;
    /** Performs a bitwise "and" (&) on a specified value and the stored value of *this. 
        Used only by integral specializations. */
    Atomic<Ty>::operator&= (Ty Value) noexcept;

    /** Performs a bitwise "or" (|) on a specified value and the stored value of *this. 
        Used only by integral specializations. */
    Atomic<Ty>::operator|= (Ty Value) volatile noexcept;
    /** Performs a bitwise "or" (|) on a specified value and the stored value of *this. 
     * Used only by integral specializations. */
    Atomic<Ty>::operator|= (Ty Value) noexcept;

    /** Performs a bitwise "exclusive or" (^) on a specified value and the stored value of *this. Used only by integral specializations. */
    Atomic<Ty>::operator^= (Ty Value) volatile noexcept;
    /** Performs a bitwise "exclusive or" (^) on a specified value and the stored value of *this. Used only by integral specializations. */
    Atomic<Ty>::operator^= (Ty Value) noexcept;

    /** Performs an atomic compare and exchange operation on *this. */
    bool compare_exchange_strong(Ty& Exp, Ty Value, memory_order Order1, memory_order Order2) volatile noexcept;
    /** Performs an atomic compare and exchange operation on *this. */
    bool compare_exchange_strong(Ty& Exp, Ty Value, memory_order Order1, memory_order Order2) noexcept;
    /** Performs an atomic compare and exchange operation on *this. */
    bool compare_exchange_strong(Ty& Exp, Ty Value, memory_order Order1 = memory_order_seq_cst) volatile noexcept;
    /** Performs an atomic compare and exchange operation on *this. */
    bool compare_exchange_strong(Ty& Exp, Ty Value, memory_order Order1 = memory_order_seq_cst) noexcept;
    
    //* Performs a weak atomic compare and exchange operation on *this. */
    bool compare_exchange_weak(Ty& Exp, Ty Value, memory_order Order1, memory_order Order2) volatile noexcept;
    //* Performs a weak atomic compare and exchange operation on *this. */
    bool compare_exchange_weak(Ty& Exp, Ty Value, memory_order Order1, memory_order Order2) noexcept;
    //* Performs a weak atomic compare and exchange operation on *this. */
    bool compare_exchange_weak(Ty& Exp, Ty Value, memory_order Order1 = memory_order_seq_cst) volatile noexcept;
    //* Performs a weak atomic compare and exchange operation on *this. */
    bool compare_exchange_weak(Ty& Exp, Ty Value, memory_order Order1 = memory_order_seq_cst) noexcept;

    /** Uses a specified value to replace the stored value of *this. */
    Ty Atomic<Ty>::exchange(Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Uses a specified value to replace the stored value of *this. */
    Ty Atomic<Ty>::exchange(Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Fetches the value stored in *this, and then adds a specified value to the stored value. */
    Ty Atomic<Ty>::fetch_add (Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Fetches the value stored in *this, and then adds a specified value to the stored value. */
    Ty Atomic<Ty>::fetch_add (Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Subtracts a specified value from the stored value. */
    Ty Atomic<Ty>::fetch_sub (Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Subtracts a specified value from the stored value. */
    Ty Atomic<Ty>::fetch_sub (Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Performs a bitwise "and" (&) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_and (Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Performs a bitwise "and" (&) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_and (Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Performs a bitwise "or" (|) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_or (Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Performs a bitwise "or" (|) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_or (Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Performs a bitwise "exclusive or" (^) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_xor (Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Performs a bitwise "exclusive or" (^) on a value and an existing value that is stored in *this. */
    Ty Atomic<Ty>::fetch_xor (Ty Value, memory_order Order = memory_order_seq_cst) noexcept;

    /** Specifies whether atomic operations on *this are lock free. */
    bool is_lock_free() const volatile noexcept;

    /** Retrieves the stored value in *this, within the specified memory constraints. */
    Ty Atomic::load(memory_order Order = memory_order_seq_cst) const volatile noexcept;
    /** Retrieves the stored value in *this, within the specified memory constraints. */
    Ty Atomic::load(memory_order Order = memory_order_seq_cst) const noexcept;

    /** Stores a specified value. */
    void Atomic<Ty>::store(Ty Value, memory_order Order = memory_order_seq_cst) volatile noexcept;
    /** Stores a specified value. */
    void Atomic<Ty>::store(Ty Value, memory_order Order = memory_order_seq_cst) noexcept;
};

//* Performs an atomic compare and exchange operation. */
template <class Ty>
inline bool atomic_compare_exchange_strong(volatile Atomic<Ty>* Atom, Ty* Exp, Ty Value) noexcept;

//* Performs an atomic compare and exchange operation. */
template <class Ty>
inline bool atomic_compare_exchange_strong(Atomic<Ty>* Atom, Ty* Exp, Ty Value) noexcept;

/** Atomically stores a value in an atomic object. */
template <class Ty>
inline Ty atomic_store_explicit(const volatile Atomic<Ty>* Atom, Ty Value) noexcept;

/** Atomically stores a value in an atomic object. */
template <class Ty>
inline Ty atomic_store_explicit(const Atomic<Ty>* Atom, Ty Value) noexcept;

/** Atomically stores a value in an atomic object. */
template <class Ty>
inline Ty atomic_store_explicit(const volatile Atomic<Ty>* Atom, Ty Value, memory_order Order) noexcept;

/** Atomically stores a value in an atomic object. */
template <class Ty>
inline Ty atomic_store_explicit(const Atomic<Ty>* Atom, Ty Value, memory_order Order) noexcept;

template <class Ty>
inline void atomic_thread_fence(memory_order Order) noexcept;

#endif //ATOMIC
