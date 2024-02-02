# Interval Tree

The Interval Tree project is an implementation of a data structure that efficiently stores intervals and allows for quick interval search and overlap detection.

## Table of Contents

- [Introduction](#introduction)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Running Tests](#running-tests)
  - [Prerequisites for Tests](#prerequisites-for-tests)
  - [Running the Tests](#running-the-tests)
- [Test Cases](#test-cases)
  - [No Overlapping Intervals](#test-case-1-no-overlapping-intervals)
  - [Overlapping Interval Found](#test-case-2-overlapping-interval-found)
  - [Overlapping Interval Found (Right Child)](#test-case-3-overlapping-interval-found-right-child)
  - [Overlapping Interval Found (Left Child)](#test-case-4-overlapping-interval-found-left-child)
  - [Overlapping Interval Found (Overlapping Both Children)](#test-case-5-overlapping-interval-found-both-children)
  - [Query Interval Fully Contained in One Interval](#test-case-6-query-interval-fully-contained-in-one-interval)
  - [Query Interval Fully Contained in Multiple Intervals](#test-case-7-query-interval-fully-contained-in-multiple-intervals)
  - [Query Interval Overlaps With Root's Right Child](#test-case-8-query-interval-overlaps-with-roots-right-child)
  - [Query Interval Overlaps With Root's Left Child](#test-case-9-query-interval-overlaps-with-roots-left-child)
  - [Query Interval Fully Contained in Root](#test-case-10-query-interval-fully-contained-in-root)
  - [Query Interval Not Found](#test-case-11-query-interval-not-found)
  - [Overlapping Intervals With Negative Values](#test-case-12-overlapping-intervals-with-negative-values)
  - [Overlapping Intervals With Zero](#test-case-13-overlapping-intervals-with-zero)
  - [Large Values](#test-case-14-large-values)
  - [Large Number of Intervals](#test-case-15-large-number-of-intervals)
  - [Query Interval With Negative Values](#test-case-16-query-interval-with-negative-values)
  - [Query Interval With Large Values](#test-case-17-query-interval-with-large-values)
  - [Query Interval With Zero](#test-case-18-query-interval-with-zero)
  - [Single Interval](#test-case-19-single-interval)
  - [Single Interval Query Outside Interval](#test-case-20-single-interval-query-outside-interval)
  - [Single Interval Query With Negative Values](#test-case-21-single-interval-query-with-negative-values)
  - [Single Interval Query With Large Values](#test-case-22-single-interval-query-with-large-values)
  - [Empty Tree](#test-case-23-empty-tree)
  - [Overlapping Intervals With Same Low and High Values](#test-case-24-overlapping-intervals-with-same-low-and-high-values)
  - [Query Interval With Same Low and High Values](#test-case-25-query-interval-with-same-low-and-high-values)
  - [Overlapping Intervals One Containing Another](#test-case-26-overlapping-intervals-one-containing-another)
  - [Overlapping Intervals One Contained Within Another](#test-case-27-overlapping-intervals-one-contained-within-another)
  - [Overlapping Intervals With Equal Intervals](#test-case-28-overlapping-intervals-with-equal-intervals)
  - [Random Intervals 1](#test-case-29-random-intervals-1)
  - [Random Intervals 2](#test-case-30-random-intervals-2)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Interval Tree is a C++ project that provides a convenient and efficient implementation of an interval tree data structure. It includes functionalities to insert intervals into the tree, search for overlapping intervals, and print the tree structure.

## Getting Started

### Prerequisites

To use or contribute to the Interval Tree project, you need the following:

- C++ compiler
- CMake

### Installation

Follow these steps to build the project:

```bash
mkdir build
cd build
cmake ..
make
```
